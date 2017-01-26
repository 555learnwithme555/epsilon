#include <poincare/square_root.h>
#include "layout/nth_root_layout.h"

extern "C" {
#include <assert.h>
#include <math.h>
}

SquareRoot::SquareRoot() :
  Function("v")
{
}

Expression::Type SquareRoot::type() const {
  return Type::SquareRoot;
}

Expression * SquareRoot::cloneWithDifferentOperands(Expression** newOperands,
        int numberOfOperands, bool cloneOperands) const {
  assert(numberOfOperands == 1);
  assert(newOperands != nullptr);
  SquareRoot * sr = new SquareRoot();
  sr->setArgument(newOperands, numberOfOperands, cloneOperands);
  return sr;
}

float SquareRoot::approximate(Context& context) const {
  return powf(m_args[0]->approximate(context), 1.0f/2.0f);
}

ExpressionLayout * SquareRoot::createLayout() const {
  return new NthRootLayout(m_args[0]->createLayout(),nullptr);
}