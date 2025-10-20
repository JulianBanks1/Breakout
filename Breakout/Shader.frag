uniform sampler2D texture;
uniform float time;
uniform vec2 resolution;

void main()
{
	vec2 uv = gl_FragCoord.xy / resolution;
	vec4 col = texture2D(texture, uv);

	gl_FragColor = vec4(col.rgb * 0.5, 1.0);
}