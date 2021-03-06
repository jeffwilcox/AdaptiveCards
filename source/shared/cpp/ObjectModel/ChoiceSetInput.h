#pragma once

#include "pch.h"
#include "BaseInputElement.h"
#include "ChoiceInput.h"
#include "Enums.h"
#include "ElementParserRegistration.h"

namespace AdaptiveCards
{
class BaseInputElement;
class ChoiceSetInput : public BaseInputElement
{
friend class ChoiceSetInputParser;
public:
    ChoiceSetInput();
    ChoiceSetInput(Spacing spacing, bool separation);
    ChoiceSetInput(Spacing spacing, bool separation, std::vector<std::shared_ptr<ChoiceInput>>& choices);

    virtual Json::Value SerializeToJsonValue() override;

    bool GetIsMultiSelect() const;
    void SetIsMultiSelect(const bool isMultiSelect);

    ChoiceSetStyle GetChoiceSetStyle() const;
    void SetChoiceSetStyle(const ChoiceSetStyle choiceSetStyle);

    std::vector<std::shared_ptr<ChoiceInput>>& GetChoices();
    const std::vector<std::shared_ptr<ChoiceInput>>& GetChoices() const;

private:
    bool m_isMultiSelect;
    ChoiceSetStyle m_choiceSetStyle;

    std::vector<std::shared_ptr<ChoiceInput>> m_choices; 
};

class ChoiceSetInputParser : public IBaseCardElementParser
{
public:
    std::shared_ptr<BaseCardElement> Deserialize(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration, 
        const Json::Value& root);
    
    std::shared_ptr<BaseCardElement> DeserializeFromString(
        std::shared_ptr<ElementParserRegistration> elementParserRegistration,
        std::shared_ptr<ActionParserRegistration> actionParserRegistration, 
        const std::string& jsonString);
};
}