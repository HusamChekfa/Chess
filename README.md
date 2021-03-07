# Chess
Making a simple Chess game for two players
- Begin: 17 February 2021

# Files
> main.cpp
> 
> Board Class
> 
>   Player Class // could make an array / vector of type Piece instead and store both in Board class
>   
> Piece Abstract Class
> 
>   Child Piece Classes - Pawn, Knight, etc ...

# Functions
> 
> I need to create a board composed of two players each with 16 starting pieces.
> 
> I need to alternate turns using a boolean value.
> 
> I need to check for check, checkmate, stalemate after each move.
> 
> I need to check for pinned pieces.
> 
> I need to check for valid moves.

# Testing Ideas
>
> Set up a board
> 
      > Check if a certain move exists for a certain Piece
  > 
      > Check if Piece is pinned
  > 
      > Check if King is in check

# Notes
> 1 and 2 represent pieces of players 1 and 2, respectively.
> 
>   1P = Player 1 Pawn. 2K = Player 2 Knight.
>   
> Squares will be large.
> 
>   White squares will have periods in them to add brightness in the terminal.
>   
>   Black squares will be left only with a border to keep the darkness of the terminal.
