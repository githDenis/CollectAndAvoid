## Engine version: 5.7

## Proejct name: CollectAndAvoid

## Old repository link:
https://github.com/githDenis/Collect-And-Avoid-Game

## Controls:
WASD - move
Space - jump
Mouse - move a camera
Esc - open pause menu
Shift - sprint

## Changed character movement parameters:
MaxWalkSpeed: 600 -> 650
GravityScale: 1 -> 1.5
JumpZVelocity: 420 -> 450

## Why is the cast check needed when you pick up a coin?
The cast is needed because EventActorBeginOverlap returns overlapped actor and we need to cast it to BP_Here. If overlapped actor is BP_Hero cast will return reference at this object. If It's not Cast will be failed

## Why is the Update Score function called in event?
Update score function isn't called in Tick function because this is bad for perfomance. So Update function is called when the player picks up a coin.

## Additional effects:
Camera shake during sprint
Niagara effect of flash during picking up a coin

## Blueprints description:
Main character class:
BP_Hero

Objects classes:
BP_Coin

Classes for enemy:
BP_Enemy
BP_EnemyContoller
BP_PatrolTargetPoint

Engine object classes:
BP_GameInstance
BP_MyGameMode

Music Manager class:
BP_MusicManager


## Packing report:
The game was packed successfully and i didn't find any mistake in game logic during testing.

## Animation source:
https://www.mixamo.com/

## Music source:
https://pixabay.com/ru/

## Asset of coin source:
https://www.cgtrader.com/

## Link to the video:


# How to run the build:
1)Open Windows\
2)Run CollectAndAvoid.exe

## Fixes:
1)Enemy now moves using patrol target points, not random location
2)Coins are placed on level by hands, not by BP_CoinSpawner; amount of coin was reduced to 14
3)Text on won and lost screen was impoved. Green color in won screen and red color in lost screen
4)Event dispatcher now process picking up a coin
5)Coin material was changed
6)Coin rotates now using Rotating Component, not in event Tick
7)Now you can an ability to set enemy speed using a variable. I couldn't to apply this logic to Sight radius
8)GameMode logic moved to GameState
