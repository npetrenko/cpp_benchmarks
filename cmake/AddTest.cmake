function (add_benchmark_test TARGET EXECS)
  add_executable(${TARGET} ${EXECS})
  target_link_libraries(${TARGET} gtest gtest_main)
  add_test(${TARGET} ${TARGET})
endfunction()
