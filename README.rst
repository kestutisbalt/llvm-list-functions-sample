=====
About
=====

This is a sample of extracting function names from llvm bitcode.


Dependencies
============

* clang 3.5
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

1. Create test file: **test.cpp**:

.. code-block:: C++

	void test_function()
	{
	}

	void test_function1()
	{
	}


2. Generate llvm bitcode:

.. code-block:: bash

	clang++-3.5 -c -emit-llvm test.cpp -o test.bc


3. Run sample:

.. code-block:: bash

	./llvm-list-functions-sample test.bc
