# Image Processing with Multithreading (C++)

## Overview
This project processes image data by applying a filter and detecting matches using multithreading.

## Implementations
- C++ version in /cpp

## How It Works
- Reads image and filter matrices from files
- Uses threads to:
  - Count occurrences of a filter
  - Locate positions of matches

Each thread processes a portion of the image to improve performance.

## Key Concepts
- Multithreading
- Matrix traversal
- Pattern matching

## What I Learned
- Using threads for parallel processing
- Improving performance with concurrency
- Applying algorithms to image data