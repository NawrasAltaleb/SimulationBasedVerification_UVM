#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 21/01/19.
//
"""
import re
import os

import argparse
parser = argparse.ArgumentParser(description='log analyzer.')

parser.add_argument('-i', dest='inputFile', metavar='file', default="", help='file with coverage status', required=True)
parser.add_argument('-o', dest='outputFile', metavar='file', default="", help='output file for report coverage', required=True)
args = parser.parse_args()

import sys
if not os.path.exists(args.inputFile):
    sys.exit("Error: \"" + args.inputFile + "\" file does not exist.")

print("\n##################### Sorting Coverage #####################")
import xml.etree.ElementTree as ET
tree = ET.parse(args.outputFile)
root = tree.getroot()

with open(args.inputFile) as inFile:
    ModuleList = list()
    ModulePerList = list()
    CoveragePointList = list()
    TestType = ''
    TestPath = ''
    for i, line in enumerate(inFile):
        TestInfo = re.search('UVM_INFO @ 0 s: my_test \[(.+) Test', line)
        if TestInfo:
            TestType = TestInfo.group(1)
            if TestType == 'Program':
                PathInfo = re.search('UVM_INFO @ 0 s: my_test \[(.+) Test: (.+)]', line)
                if PathInfo:
                    TestPath = PathInfo.group(2)

        ModuleInfo = re.search('Coverage Percentage: (.+) ([0-9]+)%    ------    (.+)', line)
        if ModuleInfo:
            if ModuleInfo.group(1) not in ModuleList:
                ModuleList.append(ModuleInfo.group(1))
                ModulePerList.append(ModuleInfo.group(2))
            else:
                ModulePerList[ModuleList.index(ModuleInfo.group(1))] = ModuleInfo.group(2)

            CoveragePointList.append(ModuleInfo.group(3))


# keep previous coverage percentages and update covered points
ModulePreviousList = list()
ModulePreviousPercentageList = list()
for module in root.find('DUT_Core'):
    # print(module.attrib['name'])
    ModulePreviousList.append(module.attrib['name'])
    ModulePreviousPercentageList.append(module.find('Coverage_Percent').text)
    module.find('Coverage_Percent').text = ModulePerList[ModuleList.index(module.attrib['name'])]
    for coverPoint in module.find('Coverage_Points').iter('Point'):
        if coverPoint.attrib['name'] in CoveragePointList:
            coverPoint.text = 'true'

# add a new test element to 'Tests' with the added percentages

TestElement = ET.SubElement(root.find('Tests'), 'Test')
TestElement.set('Type',TestType)

if TestPath != '':
    PathElement = ET.SubElement(TestElement, 'Path')
    PathElement.text = TestPath

# check added percentages
for module in ModulePreviousList:
    moduleElement = ET.SubElement(TestElement, 'Percentage')
    moduleElement.set('name',module)
    if module in ModuleList:
        if int(ModulePerList[ModuleList.index(module)]) > int(ModulePreviousPercentageList[ModulePreviousList.index(module)]):
            moduleElement.text = str(int(ModulePerList[ModuleList.index(module)]) - int(ModulePreviousPercentageList[ModulePreviousList.index(module)]))
        else:
            moduleElement.text = '0'
    else:
        moduleElement.text = '0'


tree.write(args.outputFile)
