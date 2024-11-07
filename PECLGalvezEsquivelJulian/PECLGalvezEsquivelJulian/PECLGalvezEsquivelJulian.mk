##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PECLGalvezEsquivelJulian
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian
ProjectPath            :=C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/PECLGalvezEsquivelJulian
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=julia_ntxs1ki
Date                   :=11/6/2024
CodeLitePath           :=C:/Users/julia_ntxs1ki/OneDrive/Desktop/codelite-amd64-17.0.0/codelite
MakeDirCommand         :=mkdir
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Users\julia_ntxs1ki\OneDrive\Desktop\codelite-amd64-17.0.0\codelite
Objects0=$(IntermediateDirectory)/src_Source_Files_Arbol.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_Cola.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_NodoArbol.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_NodoCola.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_Pila.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_NodoPila.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_Proceso.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_NodoLista.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_Gestor.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Source_Files_Lista.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Source_Files_Arbol.cpp$(ObjectSuffix): src/Source_Files/Arbol.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Arbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Arbol.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Arbol.cpp$(PreprocessSuffix): src/Source_Files/Arbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Arbol.cpp$(PreprocessSuffix) src/Source_Files/Arbol.cpp

$(IntermediateDirectory)/src_Source_Files_Cola.cpp$(ObjectSuffix): src/Source_Files/Cola.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Cola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Cola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Cola.cpp$(PreprocessSuffix): src/Source_Files/Cola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Cola.cpp$(PreprocessSuffix) src/Source_Files/Cola.cpp

$(IntermediateDirectory)/src_Source_Files_NodoArbol.cpp$(ObjectSuffix): src/Source_Files/NodoArbol.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/NodoArbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_NodoArbol.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_NodoArbol.cpp$(PreprocessSuffix): src/Source_Files/NodoArbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_NodoArbol.cpp$(PreprocessSuffix) src/Source_Files/NodoArbol.cpp

$(IntermediateDirectory)/src_Source_Files_NodoCola.cpp$(ObjectSuffix): src/Source_Files/NodoCola.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/NodoCola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_NodoCola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_NodoCola.cpp$(PreprocessSuffix): src/Source_Files/NodoCola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_NodoCola.cpp$(PreprocessSuffix) src/Source_Files/NodoCola.cpp

$(IntermediateDirectory)/src_Source_Files_Pila.cpp$(ObjectSuffix): src/Source_Files/Pila.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Pila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Pila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Pila.cpp$(PreprocessSuffix): src/Source_Files/Pila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Pila.cpp$(PreprocessSuffix) src/Source_Files/Pila.cpp

$(IntermediateDirectory)/src_Source_Files_NodoPila.cpp$(ObjectSuffix): src/Source_Files/NodoPila.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/NodoPila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_NodoPila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_NodoPila.cpp$(PreprocessSuffix): src/Source_Files/NodoPila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_NodoPila.cpp$(PreprocessSuffix) src/Source_Files/NodoPila.cpp

$(IntermediateDirectory)/src_Source_Files_Proceso.cpp$(ObjectSuffix): src/Source_Files/Proceso.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Proceso.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Proceso.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Proceso.cpp$(PreprocessSuffix): src/Source_Files/Proceso.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Proceso.cpp$(PreprocessSuffix) src/Source_Files/Proceso.cpp

$(IntermediateDirectory)/src_Source_Files_NodoLista.cpp$(ObjectSuffix): src/Source_Files/NodoLista.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/NodoLista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_NodoLista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_NodoLista.cpp$(PreprocessSuffix): src/Source_Files/NodoLista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_NodoLista.cpp$(PreprocessSuffix) src/Source_Files/NodoLista.cpp

$(IntermediateDirectory)/src_Source_Files_Gestor.cpp$(ObjectSuffix): src/Source_Files/Gestor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Gestor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Gestor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Gestor.cpp$(PreprocessSuffix): src/Source_Files/Gestor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Gestor.cpp$(PreprocessSuffix) src/Source_Files/Gestor.cpp

$(IntermediateDirectory)/src_Source_Files_Lista.cpp$(ObjectSuffix): src/Source_Files/Lista.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/src/Source_Files/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Source_Files_Lista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Source_Files_Lista.cpp$(PreprocessSuffix): src/Source_Files/Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Source_Files_Lista.cpp$(PreprocessSuffix) src/Source_Files/Lista.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/julia_ntxs1ki/OneDrive/Desktop/PECL-estructuras-de-datos/PECLGalvezEsquivelJulian/PECLGalvezEsquivelJulian/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


