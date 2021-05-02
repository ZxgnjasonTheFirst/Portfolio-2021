#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 30 15:40:50 2020

@author: zxgnj
"""

from numpy import exp, dot, random, amax, array, linspace
from finalProject import PokerDemo, Player
def sigmoid(x) :
    return 1/(1 + exp(-x))

def sigmoid_d(x) :
    return x * (1 - x)

class Computer(Player) :
    def __init__(self, name) :
        super().__init__(name)
        self.pokerSim = None
        self._computer = True
        self._bet = 50.0
        self._money = 500.0
        self._betted = 0.0
        self.ROUND = array([[0],  #HighCard
                            [1],  #1Pair
                            [2],  #2Pair
                            [3],  #3ofaKind
                            [4],  #Straight
                            [5],  #Flush
                            [6],  #FullHouse
                            [7],  #FourOfAKind
                            [8],  #StraightFlush
                            [9]]) #RoyalFlush
#        self.ROUND = array([[1/2,0,0,0,0,0,0,0,0,0], #HIGHCARD
#                            [0,1/2.37,0,0,0,0,0,0,0,0], #1Pair
#                            [0,0,1/21,0,0,0,0,0,0,0], #2Pair
#                            [0,0,0,1/47.3,0,0,0,0,0,0], #3ofaKind
#                            [0,0,0,0,1/254.8,0,0,0,0,0], #Straight
#                            [0,0,0,0,0,1/508.8,0,0,0,0], #Flush
#                            [0,0,0,0,0,0,1/694.17,0,0,0], #FullHouse
#                            [0,0,0,0,0,0,0,1/4165,0,0], #4ofaKind
#                            [0,0,0,0,0,0,0,0,1/72193.33,0], #StraightFlush
#                            [0,0,0,0,0,0,0,0,0,1/649740]]) #RoyalFlush
    
#        self.ROUND = array([[1,0,0,0,0,0,0,0,0,0], #HIGHCARD
#                            [0,1,0,0,0,0,0,0,0,0], #1Pair
#                            [0,0,1,0,0,0,0,0,0,0], #2Pair
#                            [0,0,0,1,0,0,0,0,0,0], #3ofaKind
#                            [0,0,0,0,1,0,0,0,0,0], #Straight
#                            [0,0,0,0,0,1,0,0,0,0], #Flush
#                            [0,0,0,0,0,0,1,0,0,0], #FullHouse
#                            [0,0,0,0,0,0,0,1,0,0], #4ofaKind
#                            [0,0,0,0,0,0,0,0,1,0], #StraightFlush
#                            [0,0,0,0,0,0,0,0,0,1]]) #RoyalFlush
#    
        self._winning_sampleR = array([[1,1,1,1,1,1,1,1,1,1]]).T

        self.syn_weightsR = 2 * random.random((1, 5)) - 1
        self.syn_weightsAFR = 2 * random.random((5, 1)) - 1

        
    def trainPRE_ROUND(self) :
        print("RANDOM SYNAPTIC WEIGHTS FOR PRE-ROUND:") 
        print(self.syn_weightsP1)
        print(self.syn_weightsAFP)
        for itera in range(10000) :
#            opponent = 2 * random.random() - 1
#        
#            for i in range(len(self.ROUND)) :
#                if opponent > max(self.ROUND[i]):
#                    opponent = i
#                    break

            input_PRE_ROUND = self.PRE_ROUND
            
            outputs1, outputs_after_sig = self.thinkPRE_ROUND(input_PRE_ROUND)
#            outputs1 = sigmoid(dot(input_PRE_ROUND, syn_weightsP1))
#                        
#            outputs_after_sig = sigmoid(dot(outputs1, syn_weightsAFP1))
            
            error = self._winning_samplePR - outputs_after_sig 
            
            
            adjustments1 = error * sigmoid_d(outputs_after_sig)                       
            
            self.syn_weightsAFP1 += dot(outputs1.T, adjustments1)
            
            syn_weightsP_error = dot(self.syn_weightsAFP1, adjustments1.T).T
            
            adjustments2 = syn_weightsP_error * sigmoid_d(outputs1)
            
            self.syn_weightsP1 += dot(input_PRE_ROUND.T, adjustments2)
            
            
            
        print("RANDOM SYNAPTIC WEIGHTS AFTER PRE-ROUND:") 
        print(self.syn_weightsP1)
        print(self.syn_weightsAFP)
        
        print("OUTPUTS FROM ROUND TO DECISIONS AFTER TRAINING:")
        print(outputs1)
        
#        print("OFFICIAL OUTPUTS: ")
#        print(official_decision)
            
        
        print("OUTPUT AFTER SIG: ")
        print(outputs_after_sig)
        
    def trainROUND(self) :
        print("RANDOM SYNAPTIC WEIGHTS FOR PRE-ROUND:") 
        print(self.syn_weightsR)
        print(self.syn_weightsAFR)
        for itera in range(1) :
            self.pokerSim = PokerDemo()
            self.pokerSim.t._seats[2].setComputer()

#            done = False
#            while not done: 
#                if not self.pokerSim.bet()  :
#                    done = True 
#            self.pokerSim.bet()
#            print(self.pokerSim.roundHandRank("Player"))
#            
            
            input_ROUND = array([[self.pokerSim.roundHandRank(self.pokerSim.t._seats[2].getName())]])
            

            
            outputs1, outputs_after_sig = self.thinkROUND(input_ROUND)
            
            self.pokerSim.decide(outputs1)
            self.pokerSim.destroy()

#            outputs1 = sigmoid(dot(input_PRE_ROUND, syn_weightsP1))
#                        
#            outputs_after_sig = sigmoid(dot(outputs1, syn_weightsAFP1))


            error = self._winning_sampleR - outputs_after_sig 
            
#            print("THIS IS THE ERROR:")
#            print(error)
            
            adjustments1 = error * sigmoid_d(outputs_after_sig)                       
            
            self.syn_weightsAFR += dot(outputs1.T, adjustments1)
            
            syn_weightsP_error = dot(self.syn_weightsAFR, adjustments1.T).T
            
            adjustments2 = syn_weightsP_error * sigmoid_d(outputs1)
            
            self.syn_weightsR += dot(input_ROUND.T, adjustments2)
            
            
            
        print("RANDOM SYNAPTIC WEIGHTS AFTER PRE-ROUND:") 
        print(self.syn_weightsR)
        print(self.syn_weightsAFR)
        
        print("OUTPUTS FROM ROUND TO DECISIONS AFTER TRAINING:")
        print(outputs1)
        
        print("WINNING SAMPLES:" , self._winning_sampleR)
#        print("OFFICIAL OUTPUTS: ")
#        print(official_decision)
        print("ERRORS AFTER TRAINING:")
        print(error)
        
        print("OUTPUT AFTER SIG: ")
        print(outputs_after_sig)
        
    def thinkPRE_ROUND(self, myInput) :
        
        outputs1 = sigmoid(dot(myInput, self.syn_weightsP1))
                        
        outputs_after_sig = sigmoid(dot(outputs1, self.syn_weightsAFP1))
        
        return outputs1, outputs_after_sig
    
    def thinkROUND(self, myInput) :
        
        inputList = []
        wantedInput = linspace(-5,5,10)
        
        for elem in myInput :
            inputList.append(wantedInput[elem])
            
#        print('THIS IS INPUT LIST:' , inputList)
        outputs1 = sigmoid(dot(inputList, self.syn_weightsR))
                        
#        print('THIS IS OUTPUTS1:', outputs1)
        outputs_after_sig = sigmoid(dot(outputs1, self.syn_weightsAFR))
        
        return outputs1, outputs_after_sig

        
def main() :
    C1 = Computer("COMP1")
    C1.trainROUND()
    decision, profit = C1.thinkROUND(array([[3]]))
    
    print("THIS IS THE DECISION: ")
    print(decision)
    print("THIS IS THE PROFIT: ") 
    print(profit)
    
   
#   h = Handrank(["AS", "9S", "9D", "9C", "8S", "AH", "8D"])
#   print(h._hand)
#   print(h.score())
#   h2 = Handrank(["AS", "8S", "9D", "9C", "8S", "AH", "8D"])
#   print(h2._hand)
#   print(h2.score())
#   
#   
#   d1 = {14: 2, 9: 3, 8: 2}
#   d2 = {14: 2, 8: 3, 9: 2}
#   
#   
#   
#   
#   
#   if h > h2 :
#       print('hand1 wins!')
#   elif h == h2 :
#       print('tie!')
#   elif h < h2:
#       print('hand2 wins!')


main()           
            