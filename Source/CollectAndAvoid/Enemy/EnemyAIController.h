#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "EnemyAIController.generated.h"

UCLASS()
class COLLECTANDAVOID_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* pawn) override;

	UFUNCTION()
	void PerceptionUpdated(AActor* actor, struct FAIStimulus stimulus);

	UPROPERTY(EditDefaultsOnly, Category = "Behavior Tree")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	UPROPERTY(EditDefaultsOnly, Category = "Sight settings")
	int32 SightRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Sight settings")
	int32 LostSightRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	TObjectPtr<USoundBase> ChaseSound;

	UPROPERTY(EditDefaultsOnly, Category = "Keys")
	FName WasCharacterSeenKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "Keys")
	FName HeroKeyName;
};
