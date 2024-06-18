#include <Geode/Geode.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <fmt/core.h>
using namespace geode::prelude;

class $modify(EditorPauseLayer) {
	bool init(LevelEditorLayer* editorLayer) {
		if (!EditorPauseLayer::init(editorLayer)) return false;
		log::error("EditorPauseLayer::init");

		CCArrayExt<GameObject*> objects = editorLayer->m_objects;
		int count = 0;
		for (auto* obj: objects) 
			if (!obj->m_isHighDetail) count++;

		if (auto menu = this->getChildByID("info-menu")) {
			log::error("menu");
			if (auto label = as<CCLabelBMFont*>(menu->getChildByID("object-count-label"))) {
				log::error("label");
				auto oldStr = label->getString();
				label->setString(fmt::format("{} (LDM: {})", oldStr, count).c_str());
			}
		}

		return true;
	}
};