"The Factory Method Pattern defines an interface for creating an object, but lets subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses."

This is a barebones example in which the WidgetFactory class is responsible for producing a simple widget. In a real world example our WidgetFactory might perform operations on our Widget before it gets passed back to us. We might also have multiple factories that produce unique variations of our widget.
