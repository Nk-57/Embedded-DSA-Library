# Embedded-DSA-Library
A Library for small embedded devices  ,without any STL from C/C++.
# Embedded Data Structures Library (C/C++)

## Project Objective

This project implements a **memory-optimized data structures library** specifically designed for **embedded systems** using **C/C++**. The goal is to provide reliable and reusable implementations of common data structures (Stack, Queue, Circular Queue, etc.) while respecting the **strict memory and real-time constraints** typical of embedded environments.

The library is intended to:

* Avoid unnecessary memory overhead
* Provide deterministic behavior
* Be safe for use in resource-constrained systems
* Serve as a reusable foundation for embedded projects (e.g., sensor buffering, CAN message queues, RTOS-style task queues)

---

## Why No STL?

The C++ Standard Template Library (STL) is powerful, but it is **not suitable for many embedded systems**. This project intentionally avoids STL to reflect **real-world embedded constraints**.

### Reasons for Avoiding STL:

* **Unpredictable Memory Usage**: STL containers often allocate memory dynamically, which can lead to heap fragmentation.
* **Non-deterministic Behavior**: Dynamic resizing and hidden allocations make timing unpredictable.
* **Limited Resources**: Many embedded systems have only a few kilobytes of RAM.
* **Lack of Control**: Embedded systems require explicit control over memory and error handling.

### What This Project Does Instead:

* Uses **static or fixed-size allocation** wherever possible
* Implements **explicit overflow and underflow checks**
* Returns clear **error codes** instead of throwing exceptions
* Ensures **O(1)** time complexity for core operations

---

## Planned Data Structures

* Stack (array-based)
* Queue (linear)
* Circular Queue (ring buffer)
* Singly Linked List (controlled dynamic allocation)

---

## Target Use Cases

* Sensor data buffering
* Communication buffers (UART, CAN, SPI)
* Producer–consumer systems
* Embedded task scheduling

---

## Author
Naren Karthik
Designed and implemented as part of an embedded systems portfolio to demonstrate **low-level programming, memory management, and system-level thinking**.
