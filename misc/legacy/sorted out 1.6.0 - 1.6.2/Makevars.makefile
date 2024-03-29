strippedLib: $(SHLIB)
		if test -e "/usr/bin/strip" & test -e "/bin/uname" & [[ `uname` == "Linux" ]] ; then /usr/bin/strip --strip-debug $(SHLIB); fi
.phony: strippedLib

#-- Compiler and Linker Flags
# -march=native
# -march (or -mcpu) builds exclusively for an architecture
# -mtune optimizes for an architecture, but builds for whole processor family
# PKG_CFLAGS="-O3 -pipe"
# PKG_CXXFLAGS="-O3 -pipe"
# PKG_CPPFLAGS=-O3 -pipe

# PKG_CFLAGS = -O3

# CFLAGS = -g -O -mtune=native
## for C++ code
# CXXFLAGS = -g -O -mtune=native

# Summary: O2 can be faster !
