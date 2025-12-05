#pragma once

#include "BehaviorTree/BTFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Math/RandomStream.h" // ~ all otrher includes first
#include "GetRandomRangedNdArray.generated.h" //always last

/**
 *
 */
UCLASS()
class TP_2DSIDESCROLLERBP_API UGetRandomRangedNdArray
    : public UBTFunctionLibrary {
  GENERATED_BODY()
  UGetRandomRangedNdArray()
      : NumericVectorDimension(3), NumericRandomSeed(0),
        NumericRangeLowBound(1), NumericRangeHighBound(0) {
    InitializeRandom(NumericRandomSeed);
    RandomValueArray.Empty();
    RandomValueArray.Reserve(NumericVectorDimension);
  };
  //~UGetRandomUnitVectorRanged();

private:
  FRandomStream RandomStream;
  int32 NumericVectorDimension;
  int32 NumericRandomSeed;
  float NumericRangeLowBound;
  float NumericRangeHighBound;
  TArray<float> RandomValueArray;
  
  // Member Functions
  void InitializeRandom(const int32 Seed) { RandomStream.Initialize(Seed); }

  void GenerateRangedRandomFloatNdArray() {
    for (float &Value : RandomValueArray) {
      Value = FMath::RandRange(NumericRangeLowBound, NumericRangeHighBound);
    }
  }

  //================================================
public:
  // UFUNCTION(BlueprintCallable, Category = "GetRandomUnitVectorRanged")
  // TArray<float> &GetRandomValueArray() {
  //   return RandomValueArray;
  // }
};
