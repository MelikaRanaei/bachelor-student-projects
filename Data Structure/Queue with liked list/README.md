# 🚀 Queue Implementation Using Linked List in C++

This project demonstrates a **Queue** data structure implemented using a **singly linked list** in C++. It's a simple yet powerful example of dynamic memory handling, with full support for standard queue operations.



## 📖 What is a Queue?<br>

A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. The first element added to the queue will be the first one to be removed. Think of it like a line of people waiting at a ticket counter — the person who gets in line first is served first.

Queues are widely used in:

- Scheduling algorithms (CPU, disk)
- Handling requests in web servers
- Breadth-first search in trees/graphs
- Buffering data streams



## 📋 Features<br>

✅ Enqueue (`push`)  
✅ Dequeue (`pop`)  
✅ Access front element (`printfront`)  
✅ Access rear element (`printrear`)  
✅ Check if the queue is empty



## 🧠 How It Works<br>

The queue is implemented using a custom `Node` structure and a `queue` class which handles:

- Dynamic memory allocation for new elements
- Pointers to both the `front` and `rear` of the queue
- Memory deallocation on `pop()`



## 📦 Operations<br>

| Command       | Description                    | Example       |
|---------------|--------------------------------|---------------|
| `1 x`         | Push integer `x` into queue    | `1 42`        |
| `2`           | Pop (dequeue) the front element| `2`           |
| `3`           | Print the front element        | `3` → `42`    |
| `4`           | Print the rear element         | `4` → `42`    |

> If the queue is empty, commands `3` and `4` return `-1`.






