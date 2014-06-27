ROOTDIR  =../..
PKGNAME  =touchvg
PROJNAME =democmds
SWIGFILE =democmds.i

CORE_INC =$(ROOTDIR)/../vgcore/core/include
CORE_SRC =$(ROOTDIR)/../vgcore/core/src

INCLUDES += -I$(CORE_INC) \
            -I$(CORE_INC)/geom \
            -I$(CORE_INC)/graph \
            -I$(CORE_INC)/canvas \
            -I$(CORE_INC)/shape \
            -I$(CORE_INC)/storage \
            -I$(CORE_INC)/cmd \
            -I$(CORE_INC)/cmdbase \
            -I$(CORE_INC)/cmdobserver \
            -I../cmds \
            -I../gate

SOURCES   =$(wildcard *.cpp) \
           $(wildcard $(CORE_SRC)/geom/*.cpp) \
           $(wildcard $(CORE_SRC)/graph/*.cpp) \
           $(wildcard $(CORE_SRC)/shape/*.cpp) \
           $(wildcard $(CORE_SRC)/cmdbase/*.cpp) \
           $(wildcard ../cmds/*.cpp)

include $(ROOTDIR)/../vgcore/core/mk/config.mk
include $(ROOTDIR)/../vgcore/core/mk/Makefile.swig
