=====
About
=====

This is a sample of extracting function names from llvm bitcode.


Dependencies
============

* llvm 3.5
* cmake


Compile
=======

Linux
-----

.. code-block:: bash

	mkdir build && cd build
	cmake ../ && make


Usage
=====

test.cpp

.. code-block:: C++

	void test_function()
	{
	}

	void test_function1()
	{
	}
