## Engine version: 5.7

## Project name: CollectAndAvoid

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
EventActorBeginOverlap returns a reference to the actor that triggered the overlap. The cast is used to check whether that actor is BP_Hero. If the cast succeeds, we can safely access the player's variables and functions. If it fails, the overlapping actor is not the player.

## Why is the Update Score function called in event?
Update score function isn't called in Tick function because this is bad for performance. So Update function is called when the player picks up a coin.

## Additional effects:
Camera shake while the player is sprinting, Niagara visual effect played when a coin is collected

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


## Performance report
# Settings: Epic
Lumen: On
Virtual Shadow Maps: On
Ray Tracing: Off
FPS: 75-80

# Settings: Epic
Lumen: Off
Virtual Shadow Maps: Off
Ray Tracing: Off
FPS: 85-90

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
9)In E_GameState descriptions of elements were renaimed from 0, 1, 2 to Playing, Won, Lost
10)Lumend and Virtual Shadow Maps were disabled
11)Renamed in engine:
   BP_EnemyContoller -> BP_EnemyController
   BP_GameInstane -> BP_GameInstance

   Renamed in README:
   Proejct -> Project
   BP_Here -> BP_Hero
   Perfomance -> Performance

   Renamed in DefaultGame.ini:
   ProjectName=CollectAndAvoid
12)Text correction in Cast check section and effects section
