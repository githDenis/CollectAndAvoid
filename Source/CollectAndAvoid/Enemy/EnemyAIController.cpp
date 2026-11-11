#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CollectAndAvoid/Hero/Hero.h"

AEnemyAIController::AEnemyAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::PerceptionUpdated);
}

void AEnemyAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	SightConfig->SightRadius = SightRadius;
	SightConfig->LoseSightRadius = LostSightRadius;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent->ConfigureSense(*SightConfig);
	SetPerceptionComponent(*AIPerceptionComponent);

	RunBehaviorTree(BehaviorTree);
}

void AEnemyAIController::PerceptionUpdated(AActor* actor, FAIStimulus stimulus)
{
	bool success = stimulus.WasSuccessfullySensed();
	Blackboard->SetValueAsBool(WasCharacterSeenKeyName, success);

	if (success)
	{
		if (stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
		{
			UGameplayStatics::PlaySound2D(GetWorld(), ChaseSound);

			TObjectPtr<AHero> Hero = Cast<AHero>(actor);

			if (Hero)
			{
				Blackboard->SetValueAsObject(HeroKeyName, Hero);
			}
		}
	}
}