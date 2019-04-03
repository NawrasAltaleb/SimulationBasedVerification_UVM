#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
//
// Created by Nawras Altaleb (nawras.altaleb89@gmail.com) on 21/01/19.
//
"""
import re
import os
import copy
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


# add a new test element to 'Tests' with the added number of coverage points
TestElement = ET.SubElement(root.find('Tests'), 'Test')
TestElement.set('Type',TestType)

if TestPath != '':
    PathElement = ET.SubElement(TestElement, 'Path')
    PathElement.text = TestPath

for module in root.find('DUT_Core'):
    CoveragePercent = ET.SubElement(TestElement, 'Coverage_Percent')
    CoveragePercent.set('name',module.attrib['name'])
    CoveragePercent.text = ModulePerList[ModuleList.index(module.attrib['name'])]

    CoverageAdded = ET.SubElement(TestElement, 'Added_CoveragePoints')
    CoverageAdded.set('name',module.attrib['name'])
    Added_CoveragePoints = 0

    if int(ModulePerList[ModuleList.index(module.attrib['name'])]) > int(module.find('Coverage_Percent').text):
        module.find('Coverage_Percent').text = ModulePerList[ModuleList.index(module.attrib['name'])]

    for coverPoint in module.find('Coverage_Points').iter('Point'):
        if coverPoint.attrib['name'] in CoveragePointList:
            coverPoint.text = 'true'

    for coveredPoint in CoveragePointList:
        for coverPoint in module.find('Uncovered_Points').iter('Point'):
            if coverPoint.attrib['name'] in CoveragePointList :
                module.find('Uncovered_Points').remove(coverPoint)
                Added_CoveragePoints += 1
                break

    CoverageAdded.text = str(Added_CoveragePoints)

tree.write(args.outputFile)
