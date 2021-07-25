#include <rapidcheck.h>
#include <rapidcheck/state.h>

class Counter {
public:
    void increase() {
        value++;
    }

    void decrease() {
        if (value > 0) {
            value--;
        }
    }

    int get() {
        return value;
    }

private:
    int value = 0;
};

struct CounterModel {
    int value = 0;
};

struct Increase : public rc::state::Command<CounterModel, Counter> {
    void apply(CounterModel &state) const override {
        state.value++;
    }

    void run(const CounterModel &state, Counter &counter) const override {
        counter.increase();
        RC_ASSERT(counter.get() == (state.value + 1));
    }
};

struct Decrease : public rc::state::Command<CounterModel, Counter> {
    void checkPreconditions(const CounterModel &state) const override {
        RC_PRE(state.value > 0);
    }

    void apply(CounterModel &state) const override {
        state.value--;
    }

    void run(const CounterModel &state, Counter &counter) const override {
        counter.decrease();
        RC_ASSERT(counter.get() == (state.value - 1));
    }
};

int main() {
    rc::check([] {
        CounterModel state;
        Counter sut;
        rc::state::check(state, sut, rc::state::gen::execOneOfWithArgs<Increase, Decrease>());
    });
    return 0;
}
