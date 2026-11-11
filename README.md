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

## Classes description:
Main character class:
   BP_Hero - Blueprint class implemented from AHere(C++ class). Class of the main character in the game

Objects classes:
   BP_Coin - class of coin that the main character can collect

Classes for enemy:
   BP_Enemy - class of the enemy that can stop the game by touching the main character
   BP_EnemyContoller - Blueprint class implemented from EnemyAIController(C++ class). Class of a brain of the enemy
   BP_PatrolTargetPoint - class of a target point. The enemy uses these target points to patrol the area

Engine object classes:
   BP_GameInstance - class of Game Instace which contains background music and current UI state
   BP_MyGameMode - class of Game Mode which contains the main rules of the game

Music Manager class:
   BP_MusicManager - class which plays background music

UI classes:
   WBP_Button - class of button that is used for main menu
   BP_MainHUD - main UI class that decides what to draw
   WBP_MainMenu - class of main menu in menu level
   WBP_MainWidget - class of main game widget
   WBP_Lost - class for lost screen
   WBP_Won - class for won screen
   WBP_Pause - class for pause menu

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
   FPS: 85-95
   # Profiling
   FPS: 85-95
   Frame: 16-17ms
   Game: 10-12ms
   Draw: 6-9ms
   RHIT: 4.5-5ms
   GPU Time: 5-5.5ms
   Input: 13-14ms
   Mem: 4.83Gb
   RenderRes: 100%
   Draws: 286-289
   Prims: 118.8K
   # Most expensive items: Frame, Game, Input

## The hardest part for me in this project
One of the hardest part in this project for me was Enchanced Input System. This system is new for me because before
I used old input system. So It took much time to understand how the system works.
Another challenge was to build an UI architecture. I tried to distribute the responsibilities between different classes.

## Packing report:
The game was packed successfully and i didn't find any mistake in game logic during testing.
But one mistake happened during the packing of project
## Error message in log:
UATHelper: Error: Packaging (Windows): LogCook: Error: GameInstanceClass contains a redirected reference '/Game/Blueprints/GameInstance/BP_GameInstane'. The intended asset will fail to load in a packaged build. Select the intended asset again in Project Settings to fix this issue.

I solved this problem by choosing other class of GameInstance and then again choose BP_GameInstance

### Resources:
   ## Animation source:
   https://www.mixamo.com/
   https://www.adobe.com/legal/terms.html

   ## Music source:
   https://pixabay.com/ru/
   https://pixabay.com/service/license-summary/

   ## Asset of coin source:
   https://www.cgtrader.com/
   https://help.cgtrader.com/hc/en-us/sections/360004404438-Licenses-and-rights

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
7)Now you have an ability to set enemy speed using a variable.
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
13)Now you have an ability to set enemy sight radius using a variable.
14)Added dark grey background to score and target score