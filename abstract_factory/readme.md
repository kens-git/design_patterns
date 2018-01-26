"The Abstract Factory Pattern provides an interface for creating *families* of related or dependent objects without specifying their concrete classes."

The Abstract Factory differs from the Factory Method because the Abstract Factory defines the interface that all concrete factories must implement, where the Factory Method only defines an interface for creating an object.

In this example we have a WidgetFactory interface that is implemented by the Factory classes. In the factory method pattern example we had one class (WidgetFactory) that produced both types of widget, where in this example we have multiple factories that each produce a different widget requiring multiple steps to complete.