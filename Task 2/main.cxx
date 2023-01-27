// ****************************************************************************
// $Id$
//
// Copyright (C) 2008-2014, Roman Lygin. All rights reserved.
// Copyright (C) 2014-2021, CADEX. All rights reserved.
//
// This file is part of the CAD Exchanger software.
//
// You may use this file under the terms of the BSD license as follows:
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// ****************************************************************************


#include <cadex/LicenseManager_Activate.h>
#include <cadex/ModelAlgo_BRepMesher.hxx>
#include <cadex/ModelAlgo_BRepMesherParameters.hxx>
#include <cadex/ModelAlgo_TopoPrimitives.hxx>
#include <cadex/ModelData_BRepRepresentation.hxx>
#include <cadex/ModelData_Model.hxx>
#include <cadex/ModelData_Body.hxx>
#include <cadex/ModelData_IndexedTriangleSet.hxx>
#include <cadex/ModelData_Part.hxx>
#include <cadex/ModelData_PolyRepresentation.hxx>
#include <cadex/ModelData_PolyShapeList.hxx>
#include <cadex/ModelData_Solid.hxx>
#include <cadex/STL_Writer.hxx>
#include <iostream>
#include "../../cadex_license.cxx"
#include "main.h"

using namespace std;
using namespace cadex;

static int NumberOfTriangles (const ModelData_PolyRepresentation& thePoly)
{
    int trianglesNb = 0;

    const ModelData_PolyShapeList& aList = thePoly.Get();
    for (size_t i = 0; i < aList.Size (); ++i) {
        const ModelData_PolyVertexSet& aPVS = aList[i];
        if (aPVS.IsOfType<ModelData_IndexedTriangleSet>()) {
            const ModelData_IndexedTriangleSet& anITS = static_cast<const ModelData_IndexedTriangleSet&> (aPVS);
            trianglesNb += anITS.NumberOfFaces();
        }
    }

    return trianglesNb;
}

static ModelData_BRepRepresentation CreateCylinderBRep (double theRadius, double theHeight)
{
    ModelData_Solid aCylinder = ModelAlgo_TopoPrimitives::CreateCylinder (theRadius, theHeight);
    ModelData_Body aBody = ModelData_Body::Create (aCylinder);
    ModelData_BRepRepresentation aBRep (aBody);
    return aBRep;
}

void AddPolyToPart (ModelData_Part& thePart,
                    ModelAlgo_BRepMesherParameters::Granularity theLOD)
{
    const ModelData_BRepRepresentation& aBRep = thePart.BRepRepresentation();

    ModelAlgo_BRepMesherParameters aParam (theLOD);

    /* Manual setting
    modelAlgo_BRepMesherParameters aParam;
    aParam.SetChordalDeflection (0.04);
    aParam.SetAngularDeflection (0.06);
    */

    ModelAlgo_BRepMesher aMesher (aParam);

    ModelData_PolyRepresentation aPoly = aMesher.Compute (aBRep);

    thePart.AddRepresentation (aPoly);

    cout << "A polygonal representation with " << NumberOfTriangles (aPoly) << " triangles has been added." << endl;
}

int main(int argc, char* argv[])
{
    auto aKey = LicenseKey::Value();

    if (!CADExLicense_Activate (aKey)) {
        cerr << "Failed to activate CAD Exchanger license." << endl;
        return 1;
    }
    
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " radius height <output_file>, where:" << endl;
        cerr << "    radius and height are cylinder parameters" << endl;
        cerr << "    <input_file> is a name of the STL file to be written" << endl;
        return 1;
    }

    const double radius = atof (argv[1]);
    const double height = atof (argv[2]);

    ModelData_BRepRepresentation aBRep = CreateCylinderBRep (radius, height);
    ModelData_Part aPart (aBRep, "Cylinder");

    //AddPolyToPart (aPart, ModelAlgo_BRepMesherParameters::Coarse);
    //AddPolyToPart (aPart, ModelAlgo_BRepMesherParameters::Medium);
    AddPolyToPart (aPart, ModelAlgo_BRepMesherParameters::Fine);

    ModelData_Model aModel;

    aModel.AddRoot (aPart);

    const char* aDest = argv[3];

    STL_Writer aWriter;

    if (!aWriter.Transfer (aModel)) {
        cerr << "Failed to transfer model data to specified format" << endl;
        return 1;
    }

    if (!aWriter.WriteFile (aDest)) {
        cerr << "Failed to write the file " << aDest << endl;
        return 1;
    }

    return 0;
}
