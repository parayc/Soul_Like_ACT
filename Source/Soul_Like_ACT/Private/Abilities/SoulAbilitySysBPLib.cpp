// Fill out your copyright notice in the Description page of Project Settings.

#include "Abilities/SoulAbilitySysBPLib.h"

USoulAbilitySysBPLib::USoulAbilitySysBPLib(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void USoulAbilitySysBPLib::CreateEventData(const AActor *Target, const AActor *Source, const FHitResult &InpHitResult, const FGameplayTag EventTag , const float EventMagnitude, FGameplayEventData &OutpEventData)
{
	FGameplayEffectContextHandle TempContextHandle(new FGameplayEffectContext());
	TempContextHandle.AddHitResult(InpHitResult);

	FGameplayEventData TempEventData;
	TempEventData.Instigator = Source;
	TempEventData.Target = Target;
	//TODO damage magnitude
	TempEventData.EventMagnitude = EventMagnitude;
	TempEventData.EventTag = EventTag;
	TempEventData.ContextHandle = TempContextHandle;

	OutpEventData = TempEventData;
}
