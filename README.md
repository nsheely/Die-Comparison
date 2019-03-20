# Die-Comparison
A simple program to generate dice and compare their win/loss to a sample die

### Summary:

  This program takes a sample die (d6 with sides 1,2,3,4,5,6 by default)
  generates die with up to a given number of pips (21 by defauly)
  and compares the win loss rate of each to the sample die.
  
  A die wins when it rolls a higher number, loses when it rolls lower, and ties re-roll.
  
### Usage: ./die_comp [-pips #pips][-faces #faces][-die {number on each side}]

  -p (-pips) #pips -- change max number of pips on generated die to #pips
  
  -f (-faces) #faces -- change the number of faces on the die, without -die will default sides to 1 - #faces
  
  -d (-die) {number on each side} -- type in, space seperated, numbers for each die on the die you want to sample against
  
### Bugs & To Do:

  Need to update comments/documentation
  
  Currently generating up to N numbers that sum to N. 
  Can reduce to generating only up to #faces numbers that sum to N.
  
  If you declare the number of faces after the faces of the die, it will
  removed the users declared face numbers and set the default
