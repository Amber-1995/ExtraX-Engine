#pragma once
#ifndef EXTRAX_MESH_OPENGL_H
#define EXTRAX_MESH_OPENGL_H
#include <glad/glad.h>
#include <ExtraX/Assert.h>
#include <ExtraX/Graphics/Mesh/MeshBase.h>

namespace ExtraX::Graphics::Base
{
	template<>
	class VertexLayout<"OpenGL"> : public Graphics::VertexLayout
	{
	public:
		VertexLayout(std::initializer_list<VertexElement> elements);

		void Bind(uint32_t = 0) override;

		static Graphics::VertexLayout* Create(Graphics::Context*, std::initializer_list<VertexElement> elements);
	};

	template<typename Vertex, typename Index>
	class StaticMesh<"OpenGL",Vertex,Index> : public Graphics::StaticMesh
	{
	private:
		uint32_t _vao;
		uint32_t _vbo;
		uint32_t _ebo;
		uint32_t _vertices_size;
		uint32_t _indices_size;

	public:
		StaticMesh(VertexLayout<"OpenGL">* vertex_layout, Vertex* vertices, uint32_t vertices_size, Index* indices, uint32_t indices_size):
			_vertices_size(vertices_size),
			_indices_size(indices_size)
		{
			glGenVertexArrays(1, &_vao);
			glGenBuffers(1, &_vbo);
			glGenBuffers(1, &_ebo);

			glBindVertexArray(_vao);

			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices_size, vertices, GL_STATIC_DRAW);

			vertex_layout->Bind();

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index) * indices_size, indices, GL_STATIC_DRAW);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
		
		virtual ~StaticMesh()
		{
			glDeleteVertexArrays(1, &_vao);
			glDeleteBuffers(1, &_vbo);
			glDeleteBuffers(1, &_ebo);
		}

		void Draw() override
		{
			glBindVertexArray(_vao);
			glDrawElements(GL_TRIANGLES, _indices_size, GL_UNSIGNED_INT, 0);
		}

		inline static Graphics::StaticMesh* Create(Graphics::Context*, Graphics::VertexLayout* vertex_layout, Vertex* vertices, uint32_t vertices_size, Index* indices, uint32_t indices_size)
		{
			VertexLayout<"OpenGL">* vertex_layout_opengl = dynamic_cast<VertexLayout<"OpenGL">*>(vertex_layout);

			XX_CORE_ASSERT(vertex_layout_opengl, "Vertex layout is not OpenGL");

			return new StaticMesh<"OpenGL", Vertex, Index>(vertex_layout_opengl, vertices, vertices_size, indices, indices_size);
		}
	};

	

}
#endif // !EXTRAX_MESH_OPENGL_H

