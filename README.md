# cs328-graph

Studying [Computer Science](https://www.cs.utexas.edu/) at the
[University of Texas at Austin](https://www.utexas.edu/) has been an
important part of who I am as a professional software developer.
While I had some skills walking in the door, UTCS's curriculum brough
both the formalisms and some practical experience to turn that skill
into something more 

Part of that process was [Dr. Nell Dale](https://en.wikipedia.org/wiki/Nell_B._Dale)'s
CS328. At the time, CS328 was the second algorithms course in a
sequence of four courses that carried undergraduates through the end
of their sophmore year.  Over the semester of CS328, there were five or six
practical implementation assignments, one of which was to implement a small
collection of graph algorithims. I mostly completed the assignment, but is
has bothered me ever since, that my implementation of a
[Hamiltonian Cycle](https://en.wikipedia.org/wiki/Hamiltonian_path) finder
never quite worked.

To close that loose end, this project is a quick implementation of
the missing algorithm, done roughly in the same style I would've used
in 1994. This predates Java, so I've used C. This predates modern
unit test frameworks, so there are just a few test graphs and are run
by the box.

Given that this is a fraction of an assignment that's a fraction of a
lower division computer science course, the implementation is  a naive, brute force
implementation. There's nothing fancy algorithmically and no fancy data structures, but a
(very slow) [Thinkpad 11e](https://www.lenovo.com/us/en/laptops/thinkpad/11e-and-chromebooks/c/thinkpad11e)
compiles it in seconds and runs it against a 30 node graph essentially
instantly. From what I (dimly) remember about the assignment, it
should fairly easily satisfy the requirements given.

## How it might look in 2020

A modern version of this would be done in something other than C,
meaning there'd be access to a standard library of useful data
structures. A fair amount of the bulk of this code is spent on
managing lists of nodes and edges, and this would mostly be delegated
to the standard library. In 2020, you also have easy access to
standard unit test libries. I'd hope a big portion of the grade
for this assignment in 2020 would be on the suite of unit tests that
shows it working.

For professional-grade work, you'd probably just use somebody else's
[implementation](https://jgrapht.org/javadoc/org.jgrapht.core/org/jgrapht/alg/interfaces/HamiltonianCycleAlgorithm.html).
