// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RPG_Project/TP_ThirdPerson/TP_ThirdPersonGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTP_ThirdPersonGameMode() {}
// Cross Module References
	RPG_PROJECT_API UClass* Z_Construct_UClass_ATP_ThirdPersonGameMode_NoRegister();
	RPG_PROJECT_API UClass* Z_Construct_UClass_ATP_ThirdPersonGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RPG_Project();
// End Cross Module References
	void ATP_ThirdPersonGameMode::StaticRegisterNativesATP_ThirdPersonGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATP_ThirdPersonGameMode_NoRegister()
	{
		return ATP_ThirdPersonGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RPG_Project,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TP_ThirdPerson/TP_ThirdPersonGameMode.h" },
		{ "ModuleRelativePath", "TP_ThirdPerson/TP_ThirdPersonGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATP_ThirdPersonGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::ClassParams = {
		&ATP_ThirdPersonGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATP_ThirdPersonGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATP_ThirdPersonGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATP_ThirdPersonGameMode, 2206615858);
	template<> RPG_PROJECT_API UClass* StaticClass<ATP_ThirdPersonGameMode>()
	{
		return ATP_ThirdPersonGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATP_ThirdPersonGameMode(Z_Construct_UClass_ATP_ThirdPersonGameMode, &ATP_ThirdPersonGameMode::StaticClass, TEXT("/Script/RPG_Project"), TEXT("ATP_ThirdPersonGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATP_ThirdPersonGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
