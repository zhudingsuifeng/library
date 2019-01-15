#!/usr/bin/env python3
#coding = utf-8

from PIL import Image,ImageDraw,ImageFont
import os
import argparse

# convert image to word with alphabet
def imagetoWordwithAlphabet(alphabet):
    inputImg, outputImg, imgSize= getPara()
    imagetoWord(inputImg, outputImg, alphabet, int(imgSize))
    print(inputImg + " convert to word image with " + imgSize + " success and save to " + outputImg)

# parsing command line arguments
def getPara():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input')   # input image file
    parser.add_argument('-o', '--output')  # output image file
    parser.add_argument('-s', '--size')    # picture scale
    args = parser.parse_args()             # get the argments from keyboard which you input
    return args.input, args.output, args.size

# convert image to word
def imagetoWord(inputImg, outputImg, alphabet, imgSize = 16):
    # os.getcwd() get current path
    # read image from file and convert rgb image to gray image
    inputImg = Image.open(inputImg).convert('L')
    newImg = Image.new('L',inputImg.size)  # create a gray image ('L') object with size (inputImg.size) which is a tuple
    font = ImageFont.truetype('/usr/share/fonts/truetype/Gubbi/Gubbi.ttf', imgSize)   # create font object with specific font and the first parament is directory of font file 
    draw = ImageDraw.Draw(newImg)     # create draw object
    # fill each pixel with step size imgSize which could show detail of character
    for h in range(0, inputImg.size[1], imgSize):
        for w in range(0, inputImg.size[0], imgSize):
            gray = inputImg.getpixel((w, h)) # get the gray value of each pixel
            draw.text((w, h), alphabet[int((len(alphabet)-1)*(255-gray)/255)], "white") # draw the text into image
            # ImageDraw object .text((w, h), charlist, color or font)
    if outputImg is not None:
        # save image object (newImg) as a file with name (outputImg) 
        newImg.save(outputImg,'jpeg')

if __name__ == "__main__":
    # alphabet which used to convert image to characters
    alphabet = ' .ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    imagetoWordwithAlphabet(alphabet)
    # ./word.py -i /home/fly/works/dog.jpg -o /home/fly/works/dog_word.jpg -s 8
