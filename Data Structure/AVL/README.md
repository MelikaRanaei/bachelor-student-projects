# 🌳 AVL Tree in C++


*A self-balancing binary search tree (AVL Tree)*

---

## 📘 What is an AVL Tree?

An **AVL Tree** is a self-balancing **Binary Search Tree (BST)**. In an AVL tree, the difference between the heights of the left and right subtrees (called the **Balance Factor**) is maintained at **-1, 0, or 1** for all nodes.

- ⚖️ Balance is restored using rotations:
  - **LL Rotation** (Single Right)
  - **RR Rotation** (Single Left)
  - **LR Rotation** (Left-Right)
  - **RL Rotation** (Right-Left)

---

## 🔧 Features of This Project

✅ Insert a node  
✅ Delete a node  
✅ Inorder & Preorder Traversals  
✅ Count leaf & non-leaf nodes  
✅ Find the lower bound of a value  
✅ Remove duplicate values  
✅ Display balance factors  
✅ Balance the tree (AVL operation)

---
## 📏 Balance Factor & Rotations

- BF(root) ➤ returns the balance factor

- setheight() ➤ updates height of all nodes

- Balance() ➤ re-balances the whole tree

- Rotations used:

  - LL_Rotation()

  - RR_Rotation()

  - LR_Rotation()

  - RL_Rotation()

--- 
## 📊 Sample Interaction

the number of chooses: 5<br>
1<br>
please enter a key for insert: 10<br>
1<br>
please enter a key for insert: 5<br>
1<br>
please enter a key for insert: 15<br>
2<br>
in order: 5 10 15<br>
pre order: 10 5 15<br>
8<br>
BF:<br>
Balance factor of  10 --> 0<br>
Balance factor of  5 --> 0<br>
Balance factor of  15 --> 0<br>
in order: 5 10 15<br>
pre order: 10 5 15<br>






