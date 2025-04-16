# 🏫 School Timetable Optimization 📅🧠

Welcome to the **School Timetable Optimization** project — a Python-based system that smartly generates and optimizes class schedules for 6th, 7th, and 8th grades. No more conflicts, overlaps, or headaches! 🎉

## 🚀 Features

- 📘 Automatically generates a weekly timetable for multiple grades.
- 👩‍🏫 Ensures no teacher is double-booked across grades.
- 🧩 Respects subject frequency and workload constraints.
- 🤖 Uses **Variable Neighborhood Search (VNS)** to improve the timetable quality.
- 📈 Evaluates timetable efficiency by minimizing the number of teaching days.

---

## 🧰 How It Works

1. **Initial Timetable Generation**:
   - Based on teacher workload & subject requirements.
   - Random time slot allocation with constraint checking.

2. **Conflict Checks**:
   - ❌ No two teachers in the same class at the same time.
   - ❌ No teacher teaching different classes simultaneously.

3. **Optimization Phase**:
   - Applies **local search heuristics** to explore better timetables.
   - Objective: reduce spread of teacher schedules across days.

---

## 🤖 Optimization Algorithm: VNS

- Random neighbor moves (slot swapping)

- Evaluates change in schedule "tightness"

- Keeps best-scoring timetable (fewer teacher days = better)

---

## 📚 Data Format

**Schedule Input**

[
  {'teacher': 'Afshari', 'subject': 'Counseling', 'work_load': 3},
  {'teacher': 'Aghavali', 'subject': 'Math', 'work_load': 8},
  ...
]

---

## 📊 Example Timetable Output




