// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RomeProjectPrototype/RomeProjectPrototypeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRomeProjectPrototypeGameModeBase() {}
// Cross Module References
	ROMEPROJECTPROTOTYPE_API UClass* Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_NoRegister();
	ROMEPROJECTPROTOTYPE_API UClass* Z_Construct_UClass_ARomeProjectPrototypeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RomeProjectPrototype();
// End Cross Module References
	void ARomeProjectPrototypeGameModeBase::StaticRegisterNativesARomeProjectPrototypeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_NoRegister()
	{
		return ARomeProjectPrototypeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RomeProjectPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "RomeProjectPrototypeGameModeBase.h" },
		{ "ModuleRelativePath", "RomeProjectPrototypeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARomeProjectPrototypeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::ClassParams = {
		&ARomeProjectPrototypeGameModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARomeProjectPrototypeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARomeProjectPrototypeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARomeProjectPrototypeGameModeBase, 1037639581);
	template<> ROMEPROJECTPROTOTYPE_API UClass* StaticClass<ARomeProjectPrototypeGameModeBase>()
	{
		return ARomeProjectPrototypeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARomeProjectPrototypeGameModeBase(Z_Construct_UClass_ARomeProjectPrototypeGameModeBase, &ARomeProjectPrototypeGameModeBase::StaticClass, TEXT("/Script/RomeProjectPrototype"), TEXT("ARomeProjectPrototypeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARomeProjectPrototypeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
