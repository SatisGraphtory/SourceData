// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "Resources/FGItemDescriptor.h"
#include "FGBuildDescriptor.generated.h"

/**
 * Descriptor for things that can be built in the BuildGun.
 */
UCLASS( Abstract )
class FACTORYGAME_API UFGBuildDescriptor : public UFGItemDescriptor
{
	GENERATED_BODY()
public:
	UFGBuildDescriptor();

#if WITH_EDITOR
	virtual void PostEditChangeProperty( struct FPropertyChangedEvent& propertyChangedEvent ) override;
#endif
	
	/** Get the category for this building descriptor. */
	UFUNCTION( BlueprintPure, Category = "FactoryGame|Descriptor|Build" )
	static TSubclassOf< class UFGBuildCategory > GetBuildCategory( TSubclassOf< UFGBuildDescriptor > inClass );

	/** Get the category for this building descriptor. */
	UFUNCTION( BlueprintCallable, Category = "FactoryGame|Descriptor|Build" )
	static void GetSubCategories( TSubclassOf< UFGBuildDescriptor > inClass, UPARAM( ref ) TArray< TSubclassOf< class UFGBuildSubCategory > >& out_subCategories );

	/** The order we want stuff in the build menu, lower is earlier */
	UFUNCTION( BlueprintPure, Category = "FactoryGame|Descriptor|Build" )
	static float GetBuildMenuPriority( TSubclassOf< UFGBuildDescriptor > inClass );

	/** The order we want stuff in the build menu, lower is earlier */
	UFUNCTION( BlueprintPure, Category = "FactoryGame|Descriptor|Build" )
	static UClass* GetHologramClass( TSubclassOf< UFGBuildDescriptor > inClass );

	/** Get the build actor class for this building descriptor. */
	UFUNCTION( BlueprintPure, Category = "FactoryGame|Descriptor|Building" )
	static TSubclassOf< AActor > GetBuildClass( TSubclassOf< UFGBuildDescriptor > inClass );

protected:
	virtual TSubclassOf< class AFGHologram > GetHologramClassInternal() const;
	virtual TSubclassOf< AActor > GetBuildClassInternal() const;

protected:
	/** The category in the build menu for this building */
	UPROPERTY( EditDefaultsOnly, Category = "Build" )
	TSubclassOf< UFGBuildCategory > mBuildCategory;

	/** The sub categories in the build menu for this building */
	UPROPERTY( EditDefaultsOnly, Category = "Build" )
	TArray< TSubclassOf< UFGBuildSubCategory > > mSubCategories;

	/** The order in the Build Menu is decided by this value. Lower values means earlier in menu. Negative values are allowed. [-N..0..N]*/
	UPROPERTY( EditDefaultsOnly, Category = "Build" )
	float mBuildMenuPriority;
};
