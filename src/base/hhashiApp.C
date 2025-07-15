#include "hhashiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
hhashiApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

hhashiApp::hhashiApp(const InputParameters & parameters) : MooseApp(parameters)
{
  hhashiApp::registerAll(_factory, _action_factory, _syntax);
}

hhashiApp::~hhashiApp() {}

void
hhashiApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<hhashiApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"hhashiApp"});
  Registry::registerActionsTo(af, {"hhashiApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
hhashiApp::registerApps()
{
  registerApp(hhashiApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
hhashiApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hhashiApp::registerAll(f, af, s);
}
extern "C" void
hhashiApp__registerApps()
{
  hhashiApp::registerApps();
}
