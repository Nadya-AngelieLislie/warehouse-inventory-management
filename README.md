# Warehouse Inventory Manager

> Console stock tracker built on a self-ordering doubly linked list.

## Overview

- A simple console tool to track warehouse stock by item name and category, with no database.

## Data / Scope

- Algorithms and Programming course, 4-person group project.

## Workflow

- Implemented a doubly linked list in C that keeps items alphabetical as they are added.
- Added insert or add-quantity, and remove or reduce stock by name.
- Added a table view of inventory and a category filter.

## Results

- Four working features: insert, reduce, view table, filter by category.
- Items stay sorted automatically on insert.
- Built in a shared multi-person codebase.

## Tech Stack

C, Doubly linked list, Dynamic memory, Pointers

## Repository Structure

```
warehouse_inventory.cpp   Console inventory app using a doubly linked list
```

## How to Run

```bash
g++ warehouse_inventory.cpp -o warehouse
./warehouse
```

## Team

Group 4: Carmenita Angelica, Ivana Joyceline, Nadya Angelie Lislie.

## Notes

- Data lives in memory only (no database), as required by the assignment.

## Author

Nadya Angelie Lislie, BINUS University (Computer Science and Statistics). [LinkedIn](https://www.linkedin.com/in/nadya-angelie-lislie/) | [GitHub](https://github.com/Nadya-AngelieLislie)

## Continuous Integration

GitHub Actions (`.github/workflows/ci.yml`) runs `ruff` and `pytest` repository-health checks on every push; run them locally with `make lint test`.
