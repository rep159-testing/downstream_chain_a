# downstream_chain_a

Second-level descendant package for REP-159 Stage 3 (Chained Extensions) validation under [REP-159](https://github.com/openrobotics/reps/pull/32).

Demonstrates transitive dependency and underlay resolution across a multi-level extension hierarchy:
```
downstream_chain_a (extendablechain)
  └── downstream_bin_a (extendablebin) [binary_import]
        └── upstream_c (extendable) [binary_import]
              └── upstream_b (extendable)
                    └── upstream_a (extendable)
```

## Build and Test

```bash
mkdir build && cd build
cmake ..
cmake --build .
ctest --output-on-failure
```