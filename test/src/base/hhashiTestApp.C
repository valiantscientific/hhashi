//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "hhashiTestApp.h"
#include "hhashiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
hhashiTestApp::validParams()
{
  InputParameters params = hhashiApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

hhashiTestApp::hhashiTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  hhashiTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

hhashiTestApp::~hhashiTestApp() {}

void
hhashiTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  hhashiApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"hhashiTestApp"});
    Registry::registerActionsTo(af, {"hhashiTestApp"});
  }
}

void
hhashiTestApp::registerApps()
{
  registerApp(hhashiApp);
  registerApp(hhashiTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
hhashiTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hhashiTestApp::registerAll(f, af, s);
}
extern "C" void
hhashiTestApp__registerApps()
{
  hhashiTestApp::registerApps();
}
