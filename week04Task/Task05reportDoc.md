# Report: Implementing Design Patterns in HMI System

## Introduction

In this task, I implemented four common design patterns—**Singleton**, **Factory**, **Observer**, and **Strategy**—to manage and control different components of an HMI (Human-Machine Interface) system. Each design pattern was applied to different aspects of the system to promote reusability, flexibility, and separation of concerns.

## Design Patterns Implemented

### 1. Singleton Pattern

- **Objective**: To ensure that the HMI system has only one instance, which manages the global state (e.g., system mode).
- **Challenge**: The main challenge was to implement the pattern in such a way that the system mode (Day/Night) is consistently accessed and controlled from a single instance of the `HMISystem` class.
- **Solution**: I used a static pointer to store the single instance of the `HMISystem` class and provided a `getInstance()` method to access it. The singleton ensures that there is only one instance of the system managing the global state.

### 2. Factory Pattern

- **Objective**: To dynamically create various control objects (e.g., `Button`, `Slider`) without exposing the details of their creation.
- **Challenge**: The challenge was to abstract the control creation process and provide a simple interface for instantiating different control types.
- **Solution**: I implemented a `ControlFactory` class with a static method `createControl()` to create instances of `Button` or `Slider`. This allowed the client code to request a control by type, while the factory handled the instantiation, promoting loose coupling.

### 3. Observer Pattern

- **Objective**: To notify different UI components (e.g., `Button`, `Slider`) when the system mode changes, enabling dynamic updates (e.g., adjusting visibility based on the mode).
- **Challenge**: The challenge was to ensure that multiple objects (observers) could subscribe to and be notified of changes to the system state (i.e., the mode).
- **Solution**: I implemented an `Observer` interface and created concrete observer classes (`ButtonObserver`, `SliderObserver`) that adjust visibility based on the current mode. The `HMISystemObserver` class manages the observers and notifies them when the mode changes.

### 4. Strategy Pattern

- **Objective**: To allow dynamic changes in the rendering behavior of controls (e.g., 2D vs. 3D rendering).
- **Challenge**: The challenge was to separate the rendering logic from the control objects and allow runtime changes in the rendering strategy.
- **Solution**: I created a `RenderingStrategy` interface and implemented two concrete strategies (`TwoDRendering` and `ThreeDRendering`). The `ControlWithRendering` class allows the rendering strategy to be changed at runtime, enabling flexibility in how controls are rendered.

## Key Learnings

- **Decoupling**: Design patterns like **Factory** and **Strategy** helped decouple the instantiation and behavior of components from the client code, promoting flexibility and reducing dependencies.
- **Code Maintainability**: Using the **Singleton** pattern for managing global state helped ensure that the system's state is controlled in a centralized manner, simplifying maintenance and avoiding inconsistencies.
- **Dynamic Updates**: The **Observer** pattern facilitated dynamic updates across multiple components when the system state changes, making it easier to maintain the system's responsiveness to changes (e.g., switching between Day/Night mode).
- **Runtime Behavior Changes**: The **Strategy** pattern allowed the system to dynamically switch rendering behaviors, enhancing its extensibility.

## Challenges Faced

- **Understanding the Relationships**: Initially, it was challenging to understand how to efficiently combine the patterns, especially the **Observer** and **Strategy** patterns, to handle dynamic changes across components. 
- **Memory Management**: Proper memory management while using raw pointers for observers and controls was tricky. I made sure to handle cleanup correctly to prevent memory leaks.

## Solutions to Challenges

- **Decoupling Observers**: To manage multiple observers, I ensured that the `HMISystemObserver` class could add and remove observers dynamically, keeping the system flexible.
- **Memory Management**: I used manual memory management techniques, such as explicitly deleting dynamically created objects (`Button`, `Slider`) to ensure that memory is freed properly and to avoid leaks.

## Conclusion

Implementing these design patterns helped structure the HMI system in a more modular and maintainable way. By applying the **Singleton**, **Factory**, **Observer**, and **Strategy** patterns, the system became more flexible, scalable, and easier to extend with new features, such as adding new control types or rendering strategies. These patterns also facilitated a cleaner separation of concerns, making the system easier to test and modify in the future.
