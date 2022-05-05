// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RPG_PROJECT_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define RPG_PROJECT_MyCharacter_generated_h

#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_SPARSE_DATA
#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_RPC_WRAPPERS
#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RPG_Project"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RPG_Project"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__OurCameraSpringArm() { return STRUCT_OFFSET(AMyCharacter, OurCameraSpringArm); }


#define RPG_Project_Source_RPG_Project_MyCharacter_h_11_PROLOG
#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_SPARSE_DATA \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_RPC_WRAPPERS \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_INCLASS \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RPG_Project_Source_RPG_Project_MyCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_SPARSE_DATA \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_INCLASS_NO_PURE_DECLS \
	RPG_Project_Source_RPG_Project_MyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RPG_PROJECT_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RPG_Project_Source_RPG_Project_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
