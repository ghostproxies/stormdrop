# StormDrop

[![StormDrop](https://repository-images.githubusercontent.com/1140914253/b8806670-f37e-42b7-b473-b44dfdc3dd61)](https://github.com/ghostproxies/stormdrop)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Period](README.md?tab=readme-ov-file#period)
- [Parallelism](README.md?tab=readme-ov-file#parallelism)
- [Reference](README.md?tab=readme-ov-file#reference)
- [Empirical Test Results](README.md?tab=readme-ov-file#empirical-test-results)
- [Speed](README.md?tab=readme-ov-file#speed)

## Introduction

StormDrop is an efficient PRNG algorithm for graphics rendering.

It's intended to replace non-cryptographic PRNGs for simple visual effects generation with indifference to mathematical biases when the requirements are 32-bit output integers, avoidance of alternating even-odd patterns, the [fastest speed](README.md?tab=readme-ov-file#speed) and [decent empirical test results](README.md?tab=readme-ov-file#empirical-test-results).

Furthermore, it has a [2⁶⁴ minimum period](README.md?tab=readme-ov-file#period), [parallelism](README.md?tab=readme-ov-file#parallelism), reversibility, [simple implementation](README.md?tab=readme-ov-file#reference) and no vendor-specific SIMD.

Subjective visual scrutiny is recommended on a case-by-case basis to ensure each StormDrop implementation results in substantial rendering performance improvements without compromising graphics quality.

## Author

StormDrop was created by [William Stafford Parsons](https://github.com/williamstaffordparsons) as a product of [GhostProxies](https://ghostproxies.com).

## License

StormDrop is licensed with the [BSD-3-Clause](LICENSE) license.

The default phrase `the copyright holder` in the 3rd clause is replaced with `GhostProxies`.

## Period

StormDrop has many possible deterministic sequences based on the seed.

A 2⁶⁴ minimum period in each sequence is proven by the mixed-in 2⁶⁴ equidistributed sequence.

## Parallelism

Each instance within a set of parallel StormDrop instances must seed `a` with a number that's unique among the set of parallel instances and must seed `b` with a number that's consistent among the set of parallel instances.

As proven by [ZoneSplit](https://github.com/ghostproxies/zonesplit), StormDrop guarantees up to 2⁶⁴ parallel instances that each output at least 2⁶⁴ results without state overlap among the set of parallel instances.

## Reference

### C Implementation

[stormdrop.c](stormdrop.c)

The `stormdrop` function modifies the state in a `struct stormdrop_state` instance to generate and return a pseudorandom `uint32_t` integer.

Each state variable (`a` and `b`) in a `struct stormdrop_state` instance must be seeded, preferably with random values.

It requires the `stdint.h` header to define both a 32-bit, unsigned integral type for `uint32_t` and a 64-bit, unsigned integral type for `uint64_t`.

### C# Implementation

[stormdrop.cs](stormdrop.cs)

The `Next` function modifies the state in a `StormDrop` instance to generate and return a pseudorandom `uint` integer.

Each state variable (`a` and `b`) in a `StormDrop` instance should be seeded with random values.

## Empirical Test Results

StormDrop passed up to 32MB in PractRand 0.96 `stdin32`.

Furthermore, it passed TestU01 1.2.3 SmallCrush.

For reproducibility, the aforementioned test results seeded each state variable with `0`.

## Speed

StormDrop was benchmarked and refined extensively during development with varying 64-bit architectures, compilers, compiler optimization settings, devices and programming languages.

The result was 1st-place speed rankings that are likely consistent across a majority of implementations compared to competing algorithms such as `lcg` and `mcg`.

Any competing PRNG algorithm with similar constraints that's faster than StormDrop suffers from severe degradation of critical [empirical test results](README.md?tab=readme-ov-file#empirical-test-results) that likely affect graphics rendering quality.
