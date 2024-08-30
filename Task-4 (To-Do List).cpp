#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>

enum Status { PENDING, COMPLETED };

struct Task {
  std::string name;
  Status status;
};
void displayTasks(const std::vector<Task> &tasks) {
  std::cout << "Task List:\n";
  for (const auto &task : tasks) {
    std::cout << "Task: " << task.name << " | Status: "
              << (task.status == COMPLETED ? "Completed" : "Pending")
              << std::endl;
  }
}
void addTask(std::vector<Task> &tasks) {
  std::string taskName;
  std::cout << "Enter the task name: ";
  std::getline(std::cin, taskName);
  tasks.push_back({taskName, PENDING});
  std::cout << "Task added: " << taskName << std::endl;
}
void markTaskCompleted(std::vector<Task> &tasks, const std::string &taskName) {
  for (auto &task : tasks) {
    if (task.name == taskName) {
      task.status = COMPLETED;
      std::cout << "Task '" << taskName << "' has been marked as completed."
                << std::endl;
      return;
    }
  }
  std::cout << "Task '" << taskName << "' not found." << std::endl;
}
void removeTask(std::vector<Task> &tasks, const std::string &taskName) {
  auto it =
      std::remove_if(tasks.begin(), tasks.end(), [&taskName](const Task &task) {
        return task.name == taskName;
      });

  if (it != tasks.end()) {
    tasks.erase(it, tasks.end());
    std::cout << "Task '" << taskName << "' has been removed.\n";
  } else {
    std::cout << "Task '" << taskName << "' not found.\n";
  }
}

int main() {
  std::vector<Task> tasks; 
  int choice;

  do {
    std::cout << "\n=== To-Do List Manager ===" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Mark Task as Completed" << std::endl;
    std::cout << "3. Remove Task" << std::endl;
    std::cout << "4. Display Tasks" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Please select an option (1-5): ";
    std::cin >> choice;
    std::cin.ignore(); 

    switch (choice) {
    case 1:
      addTask(tasks);
      break;
    case 2: {
      std::string taskName;
      std::cout << "Enter the name of the task to mark as completed: ";
      std::getline(std::cin, taskName);
      markTaskCompleted(tasks, taskName);
      break;
    }
    case 3: {
      std::string taskName;
      std::cout << "Enter the name of the task to remove: ";
      std::getline(std::cin, taskName);
      removeTask(tasks, taskName);
      break;
    }
    case 4:
      displayTasks(tasks);
      break;
    case 5:
      std::cout << "Exiting the program. Goodbye!" << std::endl;
      break;
    default:
      std::cout << "Invalid option. Please try again." << std::endl;
      break;
    }
  } while (choice != 5);

  return 0;
}
