#version 330 core
out vec4 gl_FragColor;
  
vec2 u_resolution = vec2(640,480);
vec2 CirclePosition = vec2(0,0);

float circleshape(vec2 position, float radius)
{
	return step(radius, length(position - vec2( (CirclePosition.x + u_resolution.x/2)/u_resolution.x, (CirclePosition.y + u_resolution.y/2)/u_resolution.y )) );
};

void main()
{
	vec2 position = gl_FragCoord.xy/ u_resolution;
	
	vec3 color = vec3(1.0, 1.0, 1.0);
	
	float circle = circleshape(position, 0.25)+0.5f;
	

	gl_FragColor = vec4(vec3(1, 1, 1), 0);
} 