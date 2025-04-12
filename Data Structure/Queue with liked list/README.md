# 🚀 Queue Implementation Using Linked List in C++

This project demonstrates a **Queue** data structure implemented using a **singly linked list** in C++. It's a simple yet powerful example of dynamic memory handling, with full support for standard queue operations.

---

## 📋 Features

✅ Enqueue (`push`)  
✅ Dequeue (`pop`)  
✅ Access front element (`printfront`)  
✅ Access rear element (`printrear`)  
✅ Check if the queue is empty

---

## 🧠 How It Works

The queue is implemented using a custom `Node` structure and a `queue` class which handles:

- Dynamic memory allocation for new elements
- Pointers to both the `front` and `rear` of the queue
- Memory deallocation on `pop()`

---

## 📦 Operations

| Command       | Description                    | Example       |
|---------------|--------------------------------|---------------|
| `1 x`         | Push integer `x` into queue    | `1 42`        |
| `2`           | Pop (dequeue) the front element| `2`           |
| `3`           | Print the front element        | `3` → `42`    |
| `4`           | Print the rear element         | `4` → `42`    |

> If the queue is empty, commands `3` and `4` return `-1`.

---





