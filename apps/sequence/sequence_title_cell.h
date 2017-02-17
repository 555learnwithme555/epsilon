#ifndef SEQUENCE_SEQUENCE_TITLE_CELL_H
#define SEQUENCE_SEQUENCE_TITLE_CELL_H

#include "../shared/function_title_cell.h"

namespace Sequence {

class SequenceTitleCell : public Shared::FunctionTitleCell, public Responder {
public:
  SequenceTitleCell(Responder * parentResponder = nullptr);
  void setDefinitionText(const char * textContent);
  void setFirstInitialConditionText(const char * textContent);
  void setSecondInitialConditionText(const char * textContent);
  void setColor(KDColor color) override;
  void setNumberOfSubCells(int numberOfSubcells);
  int selectedSubCell();
  void selectSubCell(int index);
  void setHighlighted(bool highlight) override;
  void setEven(bool even) override;
  int numberOfSubviews() const override;
  View * subviewAtIndex(int index) override;
  void layoutSubviews() override;
  void drawRect(KDContext * ctx, KDRect rect) const override;
  bool handleEvent(Ion::Events::Event event) override;
private:
  constexpr static KDCoordinate k_separatorThickness = 1;
  int m_numberOfSubCells;
  int m_selectedSubCell;
  EvenOddBufferTextCell m_definitionView;
  EvenOddBufferTextCell m_firstInitialConditionView;
  EvenOddBufferTextCell m_secondInitialConditionView;
};

}

#endif