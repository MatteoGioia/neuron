# Main idea

The key idea of this proposal is to use a 2 stage diffusion process to generate entire 3D scenes. 

[5] leverages scene graphs to guide scene generation, by effectively predicting the scene graph and then placing the objects.

Q1: Can SDF allow us to skip this? 

Q2: Can we somehow throw an LLM into this? Is this even a good idea?

Q3. Does the existence of [5] pose a huge problem?

### References

References on SDF:
1. Diffusion-SDF: Conditional Generative Modelling of Signed Distance Functions (ICCV 2023)
2. Diffusion-Based Signed Distance Fields for 3D Shape Generation (CVPR 2023)
3. GenSDF: Two-Stage Learning of Generalizable Signed Distance Functions (NeurIPS 2022)
4. DeepSDF: Learning Continuous Signed Distance Functions for Shape Representation (CVPR 2019)

References on Scene generation:
5. DiffuScene: Scene Graph Denoising Diffusion Probabilistic Model for Generative Indoor Scene Synthesis (2023)
6. NeuralField-LDM: Scene Generation with Hierarchical Latent Diffusion Models (2023)
7. Diffusion-based Generation, Optimization, and Planning in 3D Scenes (CVPR 2023)

Other resources:
8. Combining SDFs with Raymarching: https://www.youtube.com/watch?v=khblXafu7iA&t=1s