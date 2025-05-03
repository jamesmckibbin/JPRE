#pragma once

#include "gconst.h"

class RenderPipeline {
public:
	RenderPipeline();

	void initShaders();
	void initPipeline();
	void setAttribLayout();
	void setBlending();
};