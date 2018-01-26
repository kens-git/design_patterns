"The Command Pattern encapsulates a request as an object, thereby letting you parameterize other objects with
different requests, queue or log requests, and support undoable operations."

In this example Command is just a wrapper for the Receiver, with the Invoker class providing an interface to the pattern as a whole. In a real example we could subclass Receiver into all kinds of different objects that could provide various functionality, the most obvious being an execute/undo system for a text editor. We could also provide many more commands than just execute and undo.