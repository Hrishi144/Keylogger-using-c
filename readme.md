# Windows Keyboard Hook Logger

A simple Windows keyboard hook project written in C that demonstrates how to intercept keyboard events using the Windows Hooking API (`WH_KEYBOARD_LL`).

This project installs a low-level keyboard hook, captures key presses globally, identifies special keys (Enter, Tab, Ctrl, Alt, Function Keys, Arrow Keys, etc.), and displays them in the console.

---

## Features

* Global keyboard event monitoring
* Low-level keyboard hook (`WH_KEYBOARD_LL`)
* Detection of special keys
* Virtual-Key to Character conversion using `MapVirtualKey`
* Message loop for hook processing
* Proper hook installation and removal

---

## Language

* C

---

## Header Files Used

```c
#include <windows.h>
#include <stdio.h>
```

### Purpose

| Header File | Purpose                                                                                             |
| ----------- | --------------------------------------------------------------------------------------------------- |
| windows.h   | Provides access to the Windows API including hooks, messages, keyboard events, and system functions |
| stdio.h     | Used for console output through `printf()`                                                          |

---

## Windows API Functions Used

### SetWindowsHookEx

Installs a hook procedure into the system hook chain.

```c
SetWindowsHookEx(...)
```

Used to create the keyboard hook.

---

### CallNextHookEx

Passes the keyboard event to the next hook in the hook chain.

```c
CallNextHookEx(...)
```

Ensures other hooks continue to receive keyboard events.

---

### UnhookWindowsHookEx

Removes the installed hook.

```c
UnhookWindowsHookEx(...)
```

Called before program termination.

---

### MapVirtualKey

Converts virtual-key codes into character representations.

```c
MapVirtualKey(...)
```

Used for displaying printable characters.

---

### GetMessage

Retrieves messages from the thread's message queue.

```c
GetMessage(...)
```

Keeps the application running and allows the hook to receive events.

---

### TranslateMessage

Translates virtual-key messages into character messages.

```c
TranslateMessage(...)
```

Part of the standard Windows message loop.

---

### DispatchMessage

Dispatches a message to a window procedure.

```c
DispatchMessage(...)
```

Used in the message loop.

---

### GetModuleHandle

Obtains a handle to the current module.

```c
GetModuleHandle(NULL)
```

Required when installing the hook.

---

### GetLastError

Returns the last system error code.

```c
GetLastError()
```

Used for error reporting if hook installation fails.

---

## Important Structures

### KBDLLHOOKSTRUCT

Contains information about a keyboard event.

Fields used:

```c
vkCode
scanCode
flags
time
```

---

### MSG

Used by the Windows message loop.

```c
MSG msg;
```

Stores messages retrieved by `GetMessage()`.

---

## Project Workflow

```text
Program Starts
      |
      v
SetWindowsHookEx()
      |
      v
Keyboard Hook Installed
      |
      v
Message Loop Starts
      |
      v
User Presses Key
      |
      v
Windows Calls Hook Callback
      |
      v
Read vkCode
      |
      +--> Special Key?
      |         |
      |         +--> Print Key Name
      |
      +--> Printable Character?
                |
                +--> Convert using MapVirtualKey
                |
                +--> Print Character
      |
      v
CallNextHookEx()
```

---

## Concepts Learned

* Windows Hooking Mechanism
* Callback Functions
* Function Pointers
* Message Queues
* Windows Message Loop
* Virtual-Key Codes
* Keyboard Event Processing
* Structures and Pointer Casting
* Windows API Programming

---

## Learning Resources

### Microsoft Documentation

* SetWindowsHookEx
  https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa

* CallNextHookEx
  https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-callnexthookex

* UnhookWindowsHookEx
  https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-unhookwindowshookex

* MapVirtualKey
  https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mapvirtualkeya

* CallWindowProc
  https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-callwindowproca

---

## Disclaimer

This project was created for educational purposes to learn:

* Windows API Programming
* Keyboard Hooks
* Message Processing
* Event Handling

Use responsibly and only on systems you own or have permission to test.
