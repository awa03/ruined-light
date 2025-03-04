#ifndef LIGHTS_HPP
#define LIGHTS_HPP
#include <raylib.h>
#include <vector>
#include <cmath>

class TopDownLights {
public:
  TopDownLights(
    float radius = 300.0f, 
    Color color = YELLOW, 
    int blurPasses = 3, 
    float brightness = 1.0f
  ) : 
    lightRadius(radius), 
    lightColor(color), 
    blurIntensity(blurPasses),
    lightBrightness(std::clamp(brightness, 0.0f, 2.0f)) {
    RecreateRenderTextures();
  }

  ~TopDownLights() {
    UnloadRenderTexture(lightMask);
    UnloadRenderTexture(blurMask);
  }

  void HandleScreenResize() {
    UnloadRenderTexture(lightMask);
    UnloadRenderTexture(blurMask);

    RecreateRenderTextures();
  }

  void SetBrightness(float brightness) {
    lightBrightness = std::clamp(brightness, 0.0f, 2.0f);
  }

  float GetBrightness() const {
    return lightBrightness;
  }

  void UpdateLightPosition(Vector2 position) {
    lightPosition = position;
  }

  void ApplyBlur() {
    BeginTextureMode(blurMask);
    ClearBackground(BLACK);
    for (int i = 0; i < blurIntensity; i++) {
      float offset = i + 1.0f;
      float fadeStrength = 1.0f / (i + 1.0f);
      
      DrawTextureEx(lightMask.texture, 
        Vector2{ -offset, 0 }, 0.0f, 1.0f, 
        Fade(WHITE, 0.2f * fadeStrength * lightBrightness)
      );
      DrawTextureEx(lightMask.texture, 
        Vector2{ offset, 0 }, 0.0f, 1.0f, 
        Fade(WHITE, 0.2f * fadeStrength * lightBrightness)
      );
      DrawTextureEx(lightMask.texture, 
        Vector2{ 0, -offset }, 0.0f, 1.0f, 
        Fade(WHITE, 0.2f * fadeStrength * lightBrightness)
      );
      DrawTextureEx(lightMask.texture, 
        Vector2{ 0, offset }, 0.0f, 1.0f, 
        Fade(WHITE, 0.2f * fadeStrength * lightBrightness)
      );
    }
    EndTextureMode();

    BeginTextureMode(lightMask);
    ClearBackground(BLACK);
    DrawTexture(blurMask.texture, 0, 0, WHITE);
    EndTextureMode();
  }

  void PrepareLightMask() {
    BeginTextureMode(lightMask); 
    ClearBackground(BLACK);

    for (float r = lightRadius; r > 0; r -= 5.0f) {
      float normalizedRadius = r / lightRadius;
      float alpha = 1.0f - std::pow(normalizedRadius, 2.0f);
      
      DrawCircleGradient(
        lightPosition.x, lightPosition.y, r, 
        Fade(lightColor, alpha * 0.8f * lightBrightness), 
        Fade(BLACK, 1.0f)
      );
    }
    EndTextureMode();

    ApplyBlur();
  }

  void DrawLightEffect(Texture2D background) {
    DrawTexture(background, 0, 0, WHITE);
    
    BeginBlendMode(BLEND_ALPHA);
    DrawTexture(lightMask.texture, 0, 0, Fade(WHITE, 0.7f * lightBrightness));
    EndBlendMode();
  }

private:
  void RecreateRenderTextures() {
    lightMask = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    blurMask = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
  }

  float lightRadius;
  Color lightColor;
  Vector2 lightPosition;
  RenderTexture2D lightMask;
  RenderTexture2D blurMask;
  int blurIntensity;
  float lightBrightness;
};

#endif
