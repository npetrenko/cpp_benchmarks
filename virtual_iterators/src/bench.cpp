#include "v1.hpp"
#include "v2.hpp"
#include "inline.hpp"
#include "noinline.hpp"

#include <benchmark/benchmark.h>

template <class RangeType>
void RunReduceSum(benchmark::State& state) {
    RangeType range;
    
    while (state.KeepRunning()) {
        int last = state.range(0);
        auto r = range.CreateRange(last);
        benchmark::DoNotOptimize(ReduceSum(r));
    }
}

BENCHMARK_TEMPLATE(RunReduceSum, NonErasedInline)->Range(4, 2 << 10);
BENCHMARK_TEMPLATE(RunReduceSum, ErasedInline<v1::VFIterator>)->Range(4, 2 << 10);
BENCHMARK_TEMPLATE(RunReduceSum, ErasedInline<v2::VFIterator>)->Range(4, 2 << 10);
BENCHMARK_TEMPLATE(RunReduceSum, NonErased)->Range(4, 2 << 10);
BENCHMARK_TEMPLATE(RunReduceSum, Erased<v1::VFIterator>)->Range(4, 2 << 10);
BENCHMARK_TEMPLATE(RunReduceSum, Erased<v2::VFIterator>)->Range(4, 2 << 10);

BENCHMARK_MAIN();
