CXXFLAGS := -L./lib
UNAME := $(schell uname)


ifeq ($(UNAME), Darwin)
LIBS = libFASTWAY_STATIC_mac.a
endif
ifeq ($(UNAME), Linux)
LIBS = libFASTWAY_STATIC_linux.a
endif